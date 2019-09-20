#include <stdio.h>

#include "Constants.hpp"
#include "ExecutionTimer.hpp"
#include "Vector2_Object.hpp"
#include "Vector2_Struct.hpp"
#include "Vector2_StructOfArrays.hpp"

void addToVector2_Structs(Vector2_Struct* vec2_structs, int size, double x, double y);
void addToVector2_StructOfArrays(Vector2_StructOfArrays* vec2_structOfArrays, int size, double x, double y);

int main()
{
    ExecutionTimer timer;

    printf("\tIteration Experiment\n\nComparing array of structs, "
           "structs of arrays, and array of objects.\n\n");

    printf("Job:\t\t\tAdding two vector2s together.\n");
    printf("Job size for each:\t%d million.\n", N);

    //INITIALIZING
    ///////////////////////////////////////////////////////////////////////////////////////////
    Vector2_Struct* vec2_structs = new Vector2_Struct[JOB_LIST];

    for (long long int i = 0; i < JOB_LIST; i++)
    {
        vec2_structs[i].x = 0.0;
        vec2_structs[i].y = 0.0;
    }

    Vector2_StructOfArrays* vec2_structOfArrays = new Vector2_StructOfArrays[1];

    for (long long int i = 0; i < JOB_LIST; i++)
    {
        vec2_structOfArrays->xs[i] += 0.0;
        vec2_structOfArrays->ys[i] += 0.0;
    }

    Vector2_Object* vec2_objects = new Vector2_Object[JOB_LIST];

    //COMPUTING
    ////////////////////////////////////////////////////////////////////////////////////////
    printf("Mean averaging:\t\t%d samples.\n\n", SAMPLES);

    double timeSampleSum = 0.0;

    /*Adding to Structs*/
    for (int i = 0; i < SAMPLES; i++)
    {
        timer.setStart();
        addToVector2_Structs(vec2_structs, JOB_LIST, 1.0, 1.0);
        timer.setEnd();
        timeSampleSum += timer.getDeltaTime_s();
    }
    printf("Iterating over structs in single function:\t\t %f seconds\n", timeSampleSum / SAMPLES);
    timeSampleSum = 0.0;

    /*Adding to Struct of Arrays*/
    for (int i = 0; i < SAMPLES; i++)
    {
        timer.setStart();
        addToVector2_StructOfArrays(vec2_structOfArrays, JOB_LIST, 1.0, 1.0);
        timer.setEnd();
        timeSampleSum += timer.getDeltaTime_s();
    }
    printf("Iterating over structs of arrays in single function:\t %f seconds\n", timeSampleSum / SAMPLES);
    timeSampleSum = 0.0;

    /*Adding to Objects*/
    for (int i = 0; i < SAMPLES; i++)
    {
        timer.setStart();
        for (long long int i = 0; i < JOB_LIST; i++)
        {
            vec2_objects->add(1.0, 1.0);
        }
        timer.setEnd();
        timeSampleSum += timer.getDeltaTime_s();
    }
    printf("Iterating over each object method call:\t\t\t %f seconds\n", timeSampleSum / SAMPLES);
    timeSampleSum = 0.0;

    printf("\nPress any key to exit.");
    getchar();

    return 0;
}

void addToVector2_Structs(Vector2_Struct* vec2_structs, int size, double x, double y)
{
    for (long long int i = 0; i < size; i++)
    {
        vec2_structs[i].x += x;
        vec2_structs[i].y += y;
    }
}

void addToVector2_StructOfArrays(Vector2_StructOfArrays* vec2_structOfArrays, int size, double x, double y)
{
    for (long long int i = 0; i < size; i++)
    {
        vec2_structOfArrays->xs[i] += x;
        vec2_structOfArrays->ys[i] += y;
    }
}
