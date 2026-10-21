//const at = vec3(0, 0, 0);
whiteBallPosition = vec3(-24, 0.2, 0);

at = whiteBallPosition;
const up = vec3(0.0, 1.0, 0.0);

function sphericalEye(radius, theta, phi) {
    at = whiteBallPosition;
    return vec3(
        radius * Math.sin(theta) * Math.cos(phi),
        radius * Math.sin(theta) * Math.sin(phi),
        radius * Math.cos(theta)
    );
}




