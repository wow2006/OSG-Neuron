const vec4 diffuse_color = vec4(0.6, 0.6, 0.6, 0.0);
const vec4 specular_color = vec4(1.0, 1.0, 1.0, 1.0);

varying float specular_intensity;
varying float diffuse_intensity;

void main(void) {
    gl_FragColor = vec4(1,1,1,1) -
                (diffuse_color * diffuse_intensity) ;//+ specular_color * specular_intensity;
}
