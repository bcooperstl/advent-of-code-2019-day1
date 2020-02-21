#include <stdio.h>
#include <stdlib.h>

long calculate_fuel(long mass)
{
    return (mass/3)-2;
}

int main (int argc, char * argv[])
{
    FILE * infile=NULL;
    char buffer[256];
    long mass, fuel, total_fuel=0;
    
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
        fuel=calculate_fuel(mass);
        total_fuel+=fuel;
        fprintf(stderr, "Fuel for mass %ld is %ld\n", mass, fuel);
    }
    
    fclose(infile);
    
    printf("***Total Fueld is %ld***\n", total_fuel);

    return 0;
}
