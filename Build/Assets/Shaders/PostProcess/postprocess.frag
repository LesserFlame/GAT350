#version 430 core 
  
in vec2 texcoord; 
  
out vec4 fcolor; 
 
const float screen_height = 600.0; 

uniform sampler2D textureMap; 
uniform float offset; 

void main() 
{ 
//base
 //fcolor = texture(textureMap, texcoord); 

 vec3 color = texture(textureMap, texcoord).rgb; 
 // black / white 
 float avg = (color.r + color.g + color.b) / 3.0; 
 fcolor = vec4(vec3(avg), 1); 
 
 // invert 
 //color = 1.0 - color;
 //fcolor = vec4(color, 1.0);

 color = (color * (color.r + color.g + color.b)); //makes the saturation wonky (on purpose)
 fcolor = vec4(color, 1.0); 

 ////scanline
 //get the screen y position (uv coordinates range 0 <-> 1) 
 int y = int(texcoord.y * screen_height); 
 // set the alpha based on the modulus of the y position 
 float alpha = (y % 3 != 0) ? 1 : 0; 
 
 fcolor = vec4(color * alpha, 1); 

 // wave 
 //vec2 ttexcoord = texcoord; 
 //ttexcoord.x += sin(ttexcoord.y * 30.0 + offset) / 100.0; 
 //fcolor = texture(textureMap, ttexcoord); 

 // demonic 
 //int y = int(texcoord.y * screen_height); 
 //float alpha = (y % 3 != 0) ? 1 : 0; 

// float avg = (color.r + color.g + color.b) / 3.0; 
// fcolor = vec4(avg * alpha, 0, 0, 1.0); 
} 