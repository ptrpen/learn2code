#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define WORD_LENGTH 5
#define LIFE 5
using std::string;

//One hundred 5 letter words, from ChatGPT
std::vector<string> words
{"AMBER", "BRUSH", "CHALK", "DIVER", "EAGLE", "FLAME", "GRASP", 
"HOUND", "ICILY", "JELLY", "KOALA", "LATCH", "MIRTH", "NEXUS", 
"OCEAN", "PEACH", "QUILT", "RIVAL", "SOUND", "TULIP", "UMAMI", 
"VIXEN", "WHARF", "XEROX", "YACHT", "HELLO", "CABIN", "WORLD", 
"SNAIL", "PLANE", "ABOUT", "APPLE", "QUICK", "FROST", "OCEAN", 
"BLANK", "TIGER", "MOUSE", "EARTH", "HONEY", "LEMON", "ORBIT", 
"QUEEN", "RADIO", "ERROR", "TANGO", "UNION", "VIOLA", "WOMAN", 
"ZEBRA", "GLASS", "BLADE", "CAMEL", "DAIRY", "ELBOW", "FLUTE", 
"GLOW", "HUMOR", "IVORY", "JOKER", "KINGS", "LUNCH", "MANGO", 
"NOVEL", "ORCA", "PRISM", "QUOTA", "RAVEN", "SMILE", "TOWER", 
"UNDER", "VOUCH", "WAVES", "XYLOP", "YUMMY", "ZOOMS", "FUNNY", 
"GRATE", "HEELS", "IGLOO", "JUMPS", "KEEPS", "LIFTS", "MARCH", 
"NIGHT", "OPENS", "PLANS", "QUIET", "ROSES", "STARS", "TENTS", 
"UPSET", "VIOLE", "WINDY", "XENON"};

class Wordle
{
private:
    string input;
    string answer;
    string data[LIFE];
    int life;
public:
    Wordle():life(LIFE) {
        //banner created using chatGPT

        std::cout<<"░██╗░░░░░░░██╗░█████╗░██████╗░██████╗░██╗░░░░░███████╗"<<std::endl;
        std::cout<<"░██║░░██╗░░██║██╔══██╗██╔══██╗██╔══██╗██║░░░░░██╔════╝"<<std::endl;
        std::cout<<"░╚██╗████╗██╔╝██║░░██║██████╔╝██║░░██║██║░░░░░█████╗░░"<<std::endl;
        std::cout<<"░░████╔═████║░██║░░██║██╔══██╗██║░░██║██║░░░░░██╔══╝░░"<<std::endl;
        std::cout<<"░░╚██╔╝░╚██╔╝░╚█████╔╝██║░░██║██████╔╝███████╗███████╗"<<std::endl;
        std::cout<<"░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚═╝╚═════╝░╚══════╝╚══════╝"<<std::endl;

        std::cout << "█▀▀ █░█ █▀▀ █▀ █▀   ▀█▀ █░█ █▀▀   █░█░█ █▀█ █▀█ █▀▄ █" << std::endl;
        std::cout << "█▄█ █▄█ ██▄ ▄█ ▄█   ░█░ █▀█ ██▄   ▀▄▀▄▀ █▄█ █▀▄ █▄▀ ▄" << std::endl;


        srand (time(NULL));
        int random = rand() % words.size();
        answer = words[random];

    }
    void GetInput() {
        std::cout<<"INPUT("<<WORD_LENGTH<<" letter word): ";
        std::cin>>input;
        if(input.length() != WORD_LENGTH) {
            std::cout<<"ERROR: number of letters"<<std::endl;
            return;
        }
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
        data[LIFE - life] = input;
        life--;
    }
    bool Running() {
        if(answer.compare(input) == 0) {
            std::cout << "█▄█ █▀█ █░█   █░█░█ █▀█ █▄░█ █" << std::endl;
            std::cout << "░█░ █▄█ █▄█   ▀▄▀▄▀ █▄█ █░▀█ ▄" << std::endl;
            return 0;
        }
        if(life == 0) {
            std::cout << "█▄█ █▀█ █░█   █░░ █▀█ █▀ ▀█▀ ░ ░" << std::endl;
            std::cout << "░█░ █▄█ █▄█   █▄▄ █▄█ ▄█ ░█░ ▄ ▄" << std::endl;

            return 0;
        }
        return 1;
    }
    void Draw() {
        bool found = false;
        bool red = false;
        bool green = false;
        char oneChar = ' ';
        for(int i = 0; i < LIFE-life; i++) {
            for(int j = 0; j < WORD_LENGTH; j++) {
                for(int k=0; k < WORD_LENGTH; k++) {
                    if(data[i].at(j) == answer.at(k) ) {
                        found = true;
                        oneChar = data[i].at(j);
                        if(j == k) {
                           
                            green = true;
                            red = false;
                            break;
                            //std::cout<<"\033[1;32;40m"<<data[i].at(j); //Green(letter is used at the right place)
                        }else {
                            red = true;
                            //std::cout<<"\033[1;31;40m"<<data[i].at(j); //Red(letter is used somewhere)
                        }
                    }
                }
                if(!found) {
                    std::cout<<"\033[0;37;40m"<<data[i].at(j)<<" ";
                }
                if(red) {
                    std::cout<<"\033[1;31;40m"<<oneChar<<" "; //Red
                }
                if(green) {
                    std::cout<<"\033[1;32;40m"<<oneChar<<" "; //Green
                }
                std::cout<<"\033[0;37;40m";//<<std::endl;
                found = false;
                red = false;
                green = false;

            }

            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    string GetAnswer(){
        return answer;
    }
    void ShowData() {
        for(int i = 0; i < LIFE; i++) {
            std::cout<<data[i]<<std::endl;
        }
    }
    ~Wordle() {}
};


int main(int argc, char *argv[]) {
    Wordle wordle;
    
    while(wordle.Running()) {
        wordle.GetInput();
        wordle.Draw();
    }
    //std::cout<<wordle.GetAnswer();
    //wordle.ShowData();
  
}