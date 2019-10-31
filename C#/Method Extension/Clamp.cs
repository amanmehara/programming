using System;

public static partial class ExtensionMethods
{
    /// <summary>
    /// Compares a value to the given upper and lower bounds, in case it is not inside the bounds, it returns the upper or lower bound.
    /// </summary>
    /// <typeparam name="T">The type of the value.</typeparam>
    /// <param name="value">The value to clamp.</param>
    /// <param name="minimumValue">The lower bound for the value.</param>
    /// <param name="maximumValue">The upper bound for the value.</param>
    /// <returns>
    /// Returns the original value if it is inside the bounds. 
    /// If it is smaller than the lower bound, it returns the lower bound.
    /// If it is bigger than the upper bound, it returns the upper bound.
    /// </returns>
    public static T Clamp<T>(this T value, T minimumValue, T maximumValue) where T : IComparable<T>
    {
        if (value.CompareTo(minimumValue) < 0)
        {
            return minimumValue;
        }
        else if (value.CompareTo(maximumValue) > 0)
        {
            return maximumValue;
        }
        return value;
    }
}