document.addEventListener('DOMContentLoaded', function(){

    let game = document.querySelector('#gamebutton');
    game.addEventListener('click', function(){
        document.querySelector("#gamevid").play();
    })

    let draw = document.querySelector('#pencilbutton');
    draw.addEventListener('click', function(){
        document.querySelector("#drawvid").play();
    })

    let read = document.querySelector('#bookbutton');
    read.addEventListener('click', function(){
        document.querySelector("#readvid").play();
    })
})