varying highp vec3 vert;
varying highp vec3 vertNormal;
uniform highp vec3 lightPos;
varying vec4 v_Color;
void main() {
   //highp vec3 L = normalize(lightPos - vert);
   //highp float NL = max(dot(normalize(vertNormal), L), 0.0);
   //highp vec3 col = clamp(v_Color.xyz * 0.2 + v_Color.xyz * 0.8 * NL, 0.0, 1.0);
   gl_FragColor = v_Color;
}
