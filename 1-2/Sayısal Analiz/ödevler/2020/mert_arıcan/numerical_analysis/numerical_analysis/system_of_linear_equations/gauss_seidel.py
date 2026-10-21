from linear_system_iterative_methods import *

def gauss_seidel(current_guesses, previous_guesses, epsilon):
    is_satisfied = False
    iter_count = 0

    while not is_satisfied:
        for unknown in previous_guesses:
            #for every unknown in previous guesses...

            #get previous guess for that unknown
            previous_guess = previous_guesses[unknown]

            #getting equation for unknown
            equation_for_unk = equation_dict[unknown]

            #changing unknowns with guesses of this iteration
            equation_for_unk = equation_for_unk.subs(current_guesses)

            #calculating new guess for unknown using previous iteration guesses
            guess = equation_for_unk.evalf(subs=previous_guesses)

            #setting new guess in current_guesses dictionary
            current_guesses[unknown] = guess

            #updating diffs dictionary
            diffs[unknown] = abs(guess - previous_guess) > epsilon

        #updating iteration count
        iter_count += 1

        #assign current_guesses dictionary to previous_guesses at the end of the
        #iteration
        previous_guesses = current_guesses.copy()
        
        #printing guesses of current iteration
        print_iteration(iter_count, current_guesses)
        
        #updating the condition
        is_satisfied = not(True in diffs.values()) or not iter_count < MAX_ITER
    else:
        if not calculations_are_true(calculations, current_guesses): print("Failed to find the roots.")
    print("Total number of iterations:", iter_count)

gauss_seidel(current_guesses, previous_guesses, epsilon)

for key in sorted(list(current_guesses)):
    print(key, "=", round_if_close(current_guesses[key]))
