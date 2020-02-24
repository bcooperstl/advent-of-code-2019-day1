#include <stdio.h>
#include <stdlib.h>

long calculate_fuel(long mass)
{
    long fuel = (mass/3)-2;
    if (fuel < 0)
        fuel = 0;
    return fuel;
}

int main (int argc, char * argv[])
{
    FILE * infile=NULL;
    char buffer[256];
    long mass, fuel, module_fuel, total_fuel=0;
    
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    
    fprintf(stderr, "Opening file %s\n", argv[1]);
    
    infile=fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(1);
    }
    
    while (fgets(buffer, sizeof(buffer), infile))
    {
        mass=strtol(buffer, NULL, 10);
        module_fuel=0;
        do
        {
            fuel=calculate_fuel(mass);
            module_fuel+=fuel;
            fprintf(stderr, "Fuel for mass %ld is %ld\n", mass, fuel);
            mass = fuel;
            fprintf(stderr, "Assigning mass %ld from fuel for next calculation\n", mass);
        } while (mass > 0);
        fprintf(stderr, "Total fuel for this module is %ld\n", module_fuel);
        total_fuel+=module_fuel;
    }
    
    fclose(infile);
    
    printf("***Total Fuel is %ld***\n", total_fuel);

    return 0;
}
