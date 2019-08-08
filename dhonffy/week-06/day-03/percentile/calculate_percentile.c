int calculate_percentile(int* ordered_input, int size_of_input, int percentile)
{
    int element = (int)((float)size_of_input / 100.0 * (float)percentile);
    return ordered_input[element];
}