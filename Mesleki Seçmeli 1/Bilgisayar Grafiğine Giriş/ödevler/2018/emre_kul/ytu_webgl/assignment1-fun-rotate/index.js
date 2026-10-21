"use strict"
let gl;

let TWIST_ANGLE = 190;
const SQRT_3 = Math.sqrt(3);
const RAD = Math.PI / 180;

const createTriangle = function (center, size) {
    let height = SQRT_3 * size;
    return [
        vec2(center[0] - size, center[1] - (height / 3.0)),//left
        vec2(center[0], center[1] + (height * 2.0 / 3.0)),//top
        vec2(center[0] + size, center[1] - (height / 3.0))//right
    ];
}

const createReverseTriangle = function (center, size) {
    let height = SQRT_3 * size;
    return [
        vec2(center[0] - size, center[1] + (height * 2.0 / 3.0)),//left
        vec2(center[0], center[1] - (height / 3.0)),//top
        vec2(center[0] + size, center[1] + (height * 2.0 / 3.0))//right
    ];
}

const twistWithoutTesselation = function (vec, center, twist) {//rotate defined
    let mS = Math.sin(twist * RAD);
    let mC = Math.cos(twist * RAD);
    let tmpVec, i;
    for (i = 0; i < vec.length; i++) {
        tmpVec = vec2(vec[i][0] - center[0], vec[i][1] - center[1]);
        vec[i][0] = tmpVec[0] * mC - tmpVec[1] * mS;
        vec[i][1] = tmpVec[0] * mS + tmpVec[1] * mC;
        vec[i] = vec2(vec[i][0] + center[0], vec[i][1] + center[1]);
    }
    return vec;
}

const twistWithTesselation = function (vec, center, twist) {
    twist = twist * RAD;
    let i, tmpVec, mS, mC, distance;

    for (i = 0; i < vec.length; i++) {
        tmpVec = vec2(vec[i][0] - center[0], vec[i][1] - center[1]);
        distance = Math.sqrt(tmpVec[0] * tmpVec[0] + tmpVec[1] * tmpVec[1]);
        mS = Math.sin(twist * distance);
        mC = Math.cos(twist * distance);
        vec[i][0] = tmpVec[0] * mC - tmpVec[1] * mS;
        vec[i][1] = tmpVec[0] * mS + tmpVec[1] * mC;
        vec[i] = vec2(vec[i][0] + center[0], vec[i][1] + center[1]);
    }

    return vec;
}

const createScene = function () {
    let vertices = [];
    let twistedVertices = [];
    let trLeftTop = createTriangle(vec2(-0.5, 0.5), 0.35);
    let trLeftBottom = twistWithoutTesselation(createTriangle(vec2(-0.5, -0.5), 0.35), vec2(-0.5, -0.5), TWIST_ANGLE);
    let xI, yI, x, y, size, step, diff, trRightBottomCenter;
    x = 0.5;
    y = 0.865;
    size = 0.035;
    step = 10;
    diff = 1;
    trRightBottomCenter = vec2(x,y-diff-(size*step*SQRT_3/2+size*SQRT_3*2/3));
    for (xI = 0; xI < step * 2 - 1; xI += 2) {
        for (yI = 0; yI <= xI; yI++) {
            if (yI % 2 == 0) {
                vertices = vertices.concat(createTriangle(vec2(x + size * yI, y), size));
                twistedVertices = twistedVertices.concat(
                    twistWithTesselation(createTriangle(vec2(x + size * yI, y - diff), size), trRightBottomCenter, TWIST_ANGLE)
                );
            }
            else {
                vertices = vertices.concat(
                    createReverseTriangle(vec2(x + size * yI, y), size)
                )
                twistedVertices = twistedVertices.concat(
                    twistWithTesselation(createReverseTriangle(vec2(x + size * yI, y - diff), size), trRightBottomCenter, TWIST_ANGLE)
                );
            }
        }
        y -= size * SQRT_3;
        x -= size;
    }
    twistedVertices = twistedVertices.concat(trLeftBottom);
    vertices = vertices.concat(trLeftTop);
    return vertices.concat(twistedVertices);
}

const init = function () {
    const canvas = document.getElementById('gl-canvas');

    gl = WebGLUtils.setupWebGL(canvas);
    if (!gl)
        alert("Webgl isn't avaliable!");
    
    gl.viewport(0, 0, canvas.width, canvas.height);
    gl.clearColor(1.0, 1.0, 1.0, 1.0);

 	const program = initShaders(gl, 'vertex-shader', 'fragment-shader');
    gl.useProgram(program);

    render(canvas,program);
}

const render = function (canvas,program) {
    let i;
    let vertices = createScene();
    // Load the data into the GPU
    const bufferId = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, bufferId);
    gl.bufferData(gl.ARRAY_BUFFER, flatten(vertices), gl.STATIC_DRAW);

    // Associate out shader variables with our data buffer
    const vPos = gl.getAttribLocation(program, "vPosition");
    gl.vertexAttribPointer(vPos, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vPos);
    
    gl.clear(gl.COLOR_BUFFER_BIT);
    TWIST_ANGLE = (TWIST_ANGLE + 10);
    
    const size = vertices.length;

    for (i = 0; i < size / 2; i += 3)
        gl.drawArrays(gl.LINE_LOOP, i, 3);

    for (i = size / 2; i < size; i += 3)
        gl.drawArrays(gl.LINE_LOOP, i, 3);
    
    setTimeout(() => {
    	render(canvas,program)
    },1);
}
window.onload = init;