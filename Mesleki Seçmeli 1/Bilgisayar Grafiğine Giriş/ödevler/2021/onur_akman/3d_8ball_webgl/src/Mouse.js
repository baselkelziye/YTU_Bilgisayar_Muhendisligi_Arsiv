function handleMouseMove(event) {
    let x = event.pageX;
    let y = event.pageY;
    //let z = event.pageZ;
    let z = 0;
    Mouse.position = vec3(x, y, z);
}

function handleMouseDown(event) {
    handleMouseMove(event);

    if (event.which === 1) {
        if (!Mouse.left.down)
            Mouse.left.pressed = true;
        Mouse.left.down = true;
    } else if (event.which === 2) {
        if (!Mouse.middle.down)
            Mouse.middle.pressed = true;
        Mouse.middle.down = true;
    } else if (event.which === 3) {
        if (!Mouse.right.down)
            Mouse.right.pressed = true;
        Mouse.right.down = true;
    }

}

function handleMouseUp(event) {
    handleMouseMove(event);

    if (event.which === 1)
        Mouse.left.down = false;
    else if (event.which === 2)
        Mouse.middle.down = false;
    else if (event.which === 3)
        Mouse.right.down = false;
}
function MouseHandler() {
    this.left = new ButtonState();
    this.middle = new ButtonState();
    this.right = new ButtonState();

    this.position = vec3();

    document.onmousemove = handleMouseMove;
    document.onmousedown = handleMouseDown;
    document.onmouseup = handleMouseUp;
}

MouseHandler.prototype.reset = function () {
    this.left.pressed = false;
    this.middle.pressed = false;
    this.right.pressed = false;
}
let Mouse = new MouseHandler();


function ButtonState() {
    this.down = false;
    this.pressed = false;
}