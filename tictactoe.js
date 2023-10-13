//for chrome browser, F12
data = ['1','2','3','4','5','6','7','8','9'];

taken = [];
let Game = {
    input: -1,
    turn: 0,

    player1: 'X',
    player2: 'O',
    player: 'X',
    
    Start() {
        console.log("TIC TAC TOE");
    },
    isRunning() {
        if(this.turn < 9)
            return true;

        return false;
    },
    Check() {
        let j = 0;
        for(let i = 0; i < 3; i++) {
            if((data[i] == data[i+3]) &&( data[i] == data[i+6])) {
                return 2;
            }
            if((data[j] == data[j+1]) && (data[j] == data[j+2])) {
                return 2;
            }
            j += 3;
        }
        if((data[2] == data[4] && data[2] == data[6]) || (data[0] == data[4] && data[0] == data[8])) {
            return 2;
        }
        if(this.turn == 9) return 1;

        return 0;
    },
    Input() {
        this.input = +prompt(`${this.player}` + " SELECT THE AREA: ", "");
        
        if(this.input > 9 || this.input < 1) {
            console.log("WRONG INPUT");
            return;
        }
        if(this.input === null) {
            this.turn = 9;
            return;
        }
        for(let k = 0; k < taken.length; k++) {
            if(this.input == +taken[k]) {
                console.log("TAKEN");
                return;
            }
        }
        for(let k = 0; k < 9; k++) {
            if(+data[k] == this.input) {
                data[k] = (this.player);
                break;
            }
        }
        this.turn++;
        this.player = (this.player == 'X') ? 'O' : 'X';
        taken[this.turn] = this.input;
        return;
    },
    Draw() {
        for(let k = 0; k < 9; k +=3) {
            console.log(" " + data[k]," " + data[k+1]," " + data[k+2]);
        }
    }
};

Game.Start();

while(Game.isRunning()) {
    Game.Input();
    Game.Draw();
    if(Game.Check() == 2) {
        Game.player = (Game.player == 'X') ? 'O' : 'X';
        console.log("WINNER : " + Game.player);
        break;
    }
    else if(Game.Check() == 1) {
        console.log("DRAW");
        break;
    }

    // console.log(Game.input);
    // //console.log(Game.turn);
}
