function combsort(array input)
    gap := input.size //initialize gap size
    loop until gap = 1 and swaps = 0
        //update the gap value for a next comb. Below is an example
        gap := int(gap / 1.25)
        if gap < 1
          //minimum gap is 1
          gap := 1
        end if
        i := 0
        swaps := 0 //see Bubble Sort for an explanation
        //a single "comb" over the input list
        loop until i + gap >= input.size //see Shell sort for similar idea
            if input[i] > input[i+gap]
                swap(input[i], input[i+gap])
                swaps := 1 // Flag a swap has occurred, so the
                           // list is not guaranteed sorted
            end if
            i := i + 1
        end loop
    end loop
end function