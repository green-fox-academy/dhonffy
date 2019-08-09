int calculate_percentile(int* ordered_input, int size_of_input, int percentile)
{
    int element = size_of_input * percentile / 100;
    return ordered_input[element];
}