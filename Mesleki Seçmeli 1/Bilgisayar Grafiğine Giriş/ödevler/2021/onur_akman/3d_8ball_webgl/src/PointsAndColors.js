cubePointsAndColors = function (color) {
    const points = [];
    const colors = [];
    const vertices = cubeVertices();
    const colorList = [color, color, color, color, color, color, color, color];
    // each 3 index is a triangle. each 6 index is a face.
    // prettier-ignore
    //const indices = [1,0,3,1,3,2,2,3,7,2,7,6,3,0,4,3,4,7,6,5,1,6,1,2,4,5,6,4,6,7,5,4,0,5,0,1];
    const indices = [1, 0, 3, 1, 2, 3, 2, 3, 7, 2, 6, 7, 3, 0, 4, 3, 7, 4, 6, 5, 1, 6, 2, 1, 4, 5, 6, 4, 7, 6, 5, 4, 0, 5, 1, 0];
    for (let i of indices) {
        points.push(vertices[i]);
        colors.push(colorList[i]);
    }
    return [points, colors];
}


stickPointsAndColors = function (color) {
    const points = [];
    const colors = [];
    const vertices = cubeVertices();
    const colorList = [vec4(0, 0, 0, 1.0), vec4(0.64, 0.16, 0.16, 1.0), vec4(0, 0, 0, 1.0), vec4(0.64, 0.16, 0.16, 1.0),
    vec4(0.64, 0.16, 0.16, 1.0), vec4(0, 0, 0, 1.0), vec4(0.64, 0.16, 0.16, 1.0), vec4(0.64, 0.4, 0.4, 1.0)];
    // each 3 index is a triangle. each 6 index is a face.
    // prettier-ignore
    //const indices = [1,0,3,1,3,2,2,3,7,2,7,6,3,0,4,3,4,7,6,5,1,6,1,2,4,5,6,4,6,7,5,4,0,5,0,1];
    const indices = [1, 0, 3, 1, 2, 3, 2, 3, 7, 2, 6, 7, 3, 0, 4, 3, 7, 4, 6, 5, 1, 6, 2, 1, 4, 5, 6, 4, 7, 6, 5, 4, 0, 5, 1, 0];
    for (let i of indices) {
        points.push(vertices[i]);
        colors.push(colorList[i]);
    }
    return [points, colors];
}


legPointsAndColors = function (color) {
    const points = [];
    const colors = [];
    const vertices = cubeVertices();
    const colorList = [vec4(0.54, 0.26, 0.07, 1.0), vec4(0.54, 0.26, 0.07, 1.0), vec4(1, 1, 1, 1.0), vec4(0.54, 0.26, 0.07, 1.0),
    vec4(0.54, 0.26, 0.07, 1.0), vec4(1, 1, 1, 1.0), vec4(0.54, 0.26, 0.07, 1.0), vec4(0.54, 0.26, 0.07, 1.0)];
    // each 3 index is a triangle. each 6 index is a face.
    // prettier-ignore
    //const indices = [1,0,3,1,3,2,2,3,7,2,7,6,3,0,4,3,4,7,6,5,1,6,1,2,4,5,6,4,6,7,5,4,0,5,0,1];
    const indices = [1, 0, 3, 1, 2, 3, 2, 3, 7, 2, 6, 7, 3, 0, 4, 3, 7, 4, 6, 5, 1, 6, 2, 1, 4, 5, 6, 4, 7, 6, 5, 4, 0, 5, 1, 0];
    for (let i of indices) {
        points.push(vertices[i]);
        colors.push(colorList[i]);
    }
    return [points, colors];
}


ballPointsAndColors = function (color) {
    const points = [];
    const colors = [];
    const vertices = ballVertices();
    const colorList = [color, vec4(1, 1, 1, 1.0), color, color, color, color, color, color];
    // each 3 index is a triangle. each 6 index is a face.
    // prettier-ignore
    //const indices = [1,0,3,1,3,2,2,3,7,2,7,6,3,0,4,3,4,7,6,5,1,6,1,2,4,5,6,4,6,7,5,4,0,5,0,1];
    const indices = [1, 0, 3, 1, 2, 3, 2, 3, 7, 2, 6, 7, 3, 0, 4, 3, 7, 4, 6, 5, 1, 6, 2, 1, 4, 5, 6, 4, 7, 6, 5, 4, 0, 5, 1, 0];
    for (let i of indices) {
        points.push(vertices[i]);
        colors.push(colorList[i]);
    }
    return [points, colors];
}



tablePointsAndColors = function (color) {
    const points = [];
    const colors = [];
    const vertices = cubeVertices();
    const colorList = [vec4(0.54, 0.26, 0.07, 1.0), vec4(0.54, 0.26, 0.07, 1.0), vec4(1, 1, 1, 1.0), vec4(0.54, 0.26, 0.07, 1.0),
    vec4(0.54, 0.26, 0.07, 1.0), vec4(1, 1, 1, 1.0), vec4(0.54, 0.26, 0.07, 1.0), vec4(0.54, 0.26, 0.07, 1.0)];
    // each 3 index is a triangle. each 6 index is a face.
    // prettier-ignore
    const indices = [1, 0, 3, 1, 3, 2, 2, 3, 7, 2, 7, 6, 3, 0, 4, 3, 4, 7, 6, 5, 1, 6, 1, 2, 4, 5, 6, 4, 6, 7, 5, 4, 0, 5, 0, 1];
    for (let i of indices) {
        points.push(vertices[i]);
        colors.push(colorList[i]);
    }
    return [points, colors];
}



squarePointsAndColors = function (color) {
    const points = [];
    const colors = [];
    const vertices = cubeVertices();
    const colorList = [color, color, color, color, color, color, color, color];
    // each 3 index is a triangle. each 6 index is a face.
    // prettier-ignore
    const indices = [1, 0, 3, 1, 2, 3]; //,2,3,7,2,7,6,3,0,4,3,4,7,6,5,1,6,1,2,4,5,6,4,6,7,5,4,0,5,0,1];
    for (let i of indices) {
        points.push(vertices[i]);
        colors.push(colorList[i]);
    }
    return [points, colors];
}


facePointsAndColors = function (color) {
    const points = [];
    const colors = [];
    const vertices = faceVertices();
    const colorList = [color, color, color, color, color, color, color, color];
    // each 3 index is a triangle. each 6 index is a face.
    // prettier-ignore
    const indices = [1, 0, 3, 1, 2, 3, 2, 3, 7, 2, 7, 6, 3, 0, 4, 3, 4, 7, 6, 5, 1, 6, 1, 2, 4, 5, 6, 4, 6, 7, 5, 4, 0, 5, 0, 1];
    for (let i of indices) {
        points.push(vertices[i]);
        colors.push(colorList[i]);
    }
    return [points, colors];
}