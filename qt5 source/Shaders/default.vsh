attribute vec4 vertex;
attribute vec3 normal;
varying vec3 vert;
varying vec3 vertNormal;
varying vec4 v_Color;
uniform mat4 projMatrix;
uniform mat4 mvMatrix;
uniform mat3 normalMatrix;
void main() {
   vert = vertex.xyz;
   vertNormal = normalMatrix * normal;
   v_Color = gl_Color;
   gl_Position = projMatrix * mvMatrix * vertex;
}
