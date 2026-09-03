#include<iostream>
using namespace std;
class State{
    public:
    virtual void pressPlay()=0;
    virtual void pressPause()=0;
    virtual void pressStop()=0;
    virtual void display()=0;
    virtual ~State()=default;
};
class PlayingState :public State{
    public:
    void pressPlay() override{
        cout<<"Starting playback"<<endl;
    }
    void pressPause() override{
        cout<<"pausing playback"<<endl;
    }
    void pressStop() override{
        cout<<"Stopping Playback"<<endl;
    }
    void display() override{
        cout<<"Playing State"<<endl;
    } 
};
class PausedState :public State{
    public:
    void pressPlay() override{
        cout<<"Resuming playback"<<endl;
    }
    void pressPause() override{
        cout<<"already paused playback"<<endl;
    }
    void pressStop() override{
        cout<<"Stopping Playback"<<endl;
    }
    void display() override{
        cout<<"paused  State"<<endl;
    } 
};
class StoppedState :public State{
    public:
    void pressPlay() override{
        cout<<"Starting playback from start"<<endl;
    }
    void pressPause() override{
        cout<<"cant paused media is already stopped"<<endl;
    }
    void pressStop() override{
        cout<<"already Playback"<<endl;
    }
    void display() override{
        cout<<"Stopped State"<<endl;
    } 
};
class MediaPlayer{
    State* state;
    public:
    MediaPlayer(State *s){
        state=s;
    }
    void setState(State *s){
        state=s;
    }
    void play(){
        state->pressPlay();
    }
    void stop(){
        state->pressStop();
    }
    void pause(){
        state->pressPause();
    }
    void display(){
        state->display();
    }
};

int main(){
    MediaPlayer*m =new MediaPlayer(new PlayingState());
    m->display();
    m->play();
    m->pause();
    m->setState(new PausedState());
    m->pause();
    m->play();
    return 0;
}