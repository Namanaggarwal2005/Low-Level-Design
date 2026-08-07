#include <iostream>
using namespace std;

// Target interface
class MediaPlayer {
public:
    virtual void play() = 0;
    virtual ~MediaPlayer() = default;
};

// Existing class (Adaptee)
class Mp3Player {
public:
    void playMp3() {
        cout << "Playing MP3 file\n";
    }
};

// Adapter
class Mp3Adapter : public MediaPlayer {
    Mp3Player* player;

public:
    Mp3Adapter(Mp3Player* player) {
        this->player = player;
    }

    void play() override {
        player->playMp3();
    }
};

int main() {
    Mp3Player mp3;

    MediaPlayer* player = new Mp3Adapter(&mp3);

    player->play();   // Calls playMp3()

    delete player;
}