function KeyboardHandler() {
    this.key = "";
    this.isPressing = false;
    document.onkeypress = handleKeyPress;
    document.onkeyup = handleKeyUp;
}

KeyboardHandler.prototype.reset = function () {
    this.key = "";
    this.isPressing = false;
}

function handleKeyPress(evt) {
    Keyboard.isPressing = true;
    evt = evt || window.event;
    var charCode = evt.keyCode || evt.which;
    Keyboard.key = String.fromCharCode(charCode);

};

function handleKeyUp(evt) {
    Keyboard.isPressing = false;
};
let Keybord = new KeyboardHandler();