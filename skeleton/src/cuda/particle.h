#pragma once


namespace CUDA{


#ifdef __CUDACC__

typedef float2 vec2_t;
typedef float3 vec3_t;
typedef float4 vec4_t;
typedef quaternion<float> quat_t;
#define ATTRIBUTES __attribute__((packed))
#define ALIGNMENT __align__(4)

#else

typedef vec2 vec2_t;
typedef vec3 vec3_t;
typedef vec4 vec4_t;
typedef glm::quat quat_t;
#define ATTRIBUTES
#define ALIGNMENT

#endif


class ALIGNMENT Particle
{
public:
    vec3_t position;
    float radius;
    vec4_t color;
    vec3_t impulse;
    float lifetime;
    
    vec4_t initial_color;
    vec3_t initial_position;
	float max_lifetime;

    Particle(){}

}ATTRIBUTES;


    void test();
    void resetParticles(void* particles, int numberOfParticles, int x, int z, float cornerX, float cornerY, float cornerZ, float distance);
    void integrateParticles(void* particles, int numberOfParticles, float dt);

}
