#version 330
precision highp float;
in vec2 textCord;
in vec3 normal;
in vec3 worldPos;

out vec4 fragColor;

struct BaseLight
{
	float intensity;
	vec3 color;
};

struct DirectionalLight
{
	BaseLight base;
	vec3 direction;
};


uniform sampler2D sampler;
uniform vec3 baseColor;
uniform vec3 ambientLight;

uniform float specularIntensity;
uniform float specularPower;
uniform vec3 eyePos;

uniform DirectionalLight directionalLight;




vec4 calcLight(BaseLight base, vec3 direction, vec3 normal)
{
    vec3 colorIntensity = base.color;
    float diffuseContribution = max(dot(normal, -direction), 0.0);
	vec4 diffuseColor = vec4(colorIntensity, 1.0) * diffuseContribution * base.intensity;
	 
	vec3 directionToEye = normalize(eyePos - worldPos);
    vec3 halfDirection = normalize(directionToEye - direction);
    
    float specularFactor = max(dot(halfDirection, normal), 0.0);
    specularFactor = pow(specularFactor, specularPower);

    vec4 specularColor = vec4(colorIntensity, 1.0) * specularIntensity * specularFactor;
	return  diffuseColor + specularColor;
}

vec4 calcDirectionlLight(DirectionalLight directionLight, vec3 normal)
{
	return calcLight(directionLight.base, normalize(directionLight.direction), normal);
}



void main()
{
	vec4 totalLight = vec4(ambientLight, 1);
	//vec4 color = vec4(baseColor, 1.0);
	vec4 color  = vec4(baseColor, 1.0) * texture2D(sampler, textCord);
	
	totalLight += calcDirectionlLight(directionalLight, normalize(normal));
	
	fragColor = color * totalLight;
}