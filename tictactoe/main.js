const board = document.getElementById("main");
const data = ['1','2','3','4','5','6','7','8','9'];
const PLAYER = 'X';
const PLAYER2 = 'O';

let gameGoing = true;
let turn = 0;
let currentPlayer = PLAYER;

for(let i = 1; i < 10; i++) {
    if(i%3 == 0)
        board.innerHTML += `<button type="button" class="board" id="${i}" onclick="Clicked(${i})">${i}</button><br>`;
    else
        board.innerHTML += `<button type="button" class="board" id="${i}" onclick="Clicked(${i})">${i}</button>`;
}
const btn = document.querySelectorAll('button');

btn.forEach((butn) => {
    butn.style.width = '100px';
    butn.style.height = '100px';
    butn.style.margin = '1px';
    butn.style.position = 'static';
  });

  function changePlayer() {
    currentPlayer = (currentPlayer == PLAYER) ? PLAYER2 : PLAYER;
  }

function Clicked(x) {
    if(data[x-1] != PLAYER && data[x-1] != PLAYER2 && turn < 9 && gameGoing) {
        ++turn;
        data[x-1] = currentPlayer;
        Check();
        board.innerHTML += currentPlayer + ': ' + x + '<br>';
        document.querySelector(`[id = "${x}"]`).innerHTML = currentPlayer;
        
        document.querySelector(`[id = "${x}"]`).style.backgroundColor = (currentPlayer == PLAYER) ? 'coral' : 'aquamarine';
        changePlayer();
    }
    datashow();
} 

function datashow() {
    console.log(data);
    console.log("turn: " + turn);
}

/**
 * 0 1 2
 * 3 4 5
 * 6 7 8
 */
const Check = function(){
    for(let i = 0; i < 9; i += 3) {
        if((data[i] === data[i+1] && data[i] === data[i+2])) {
            document.body.innerHTML += `<h1 style="font-size:70px;">WINNER IS ${currentPlayer}</h1>`;
            gameGoing = false;
        }
    }
    for(let j=0; j< 3; j++) {
        if(data[j] === data[j+3] && data[j] === data[j+6]) {
            document.body.innerHTML += `<h1 style="font-size:70px;">WINNER IS ${currentPlayer}</h1>`;
            gameGoing = false;
        }
    }
    if(data[0] === data[4] && data[0] === data[8] || data[2] === data[4] && data[2] === data[6]) {
        document.body.innerHTML += `<h1 style="font-size:70px;">WINNER IS ${currentPlayer}</h1>`;
        gameGoing = false;
    }
    if(turn == 9) {
        document.body.innerHTML += `<h1 style="font-size:70px;">DRAW<h1>`;
        gameGoing = false;
    }
}
