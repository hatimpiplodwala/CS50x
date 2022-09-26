document.addEventListener('DOMContentLoaded', function(){

    var audio = new Audio("/sounds/batmanaudio.mp3");

    let sound = document.querySelector("#soundbutton");
    sound.addEventListener('click', function(){

        if(!audio.paused)
        {
            audio.pause();
        }
        else
        {
            audio.play();
        }
    })
})