document.addEventListener('DOMContentLoaded', function(){

    let tennis = document.querySelector('#tennisbutton');
    tennis.addEventListener('click', function(){
        document.querySelector("#tennisvid").play();
    })

    let ufc = document.querySelector('#ufcbutton');
    ufc.addEventListener('click', function(){
        document.querySelector("#ufcvid").play();
    })

    let vfx = document.querySelector('#vfxbutton');
    vfx.addEventListener('click', function(){
        document.querySelector("#vfxvid").play();
    })
})