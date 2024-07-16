import os
import random
import argparse

MIN_INT = -2147483648
MAX_INT = 2147483648

def run_push_swap(lst:list, args, checker_flag:bool=False):
    if len(lst) == 1:
        arg = str(lst[0])
    elif len(lst) > 1:
        arg = " ".join(str(l) for l in lst)
    else:
        arg = ""

    push_swap = os.path.join(args.PUSH_SWAP_PATH, "push_swap")
    checker = os.path.join(args.CHECKER_LINUX_PATH, "checker_linux")

    command1 = " ".join([push_swap, arg, "| wc -l"])
    command2 = " ".join([push_swap, arg, "|", checker, arg])

    wc = os.popen(command1).read().strip()
    if checker_flag:
        solutions = os.popen(command2).read().strip()
        return (int(wc), solutions)
    return (wc)

def warpping_print(s:str):
    print("="*100)
    print(s)

def make_random_lst(size:int):
    lst = random.sample(range(MIN_INT, MAX_INT+1), size)
    return (lst)

def check_score(size:int, wc:int):
    if size == 100:
        if (wc < 700):
            return (5)
        elif (wc < 900):
            return (4)
        elif (wc < 1100):
            return (3)
        elif (wc < 1300):
            return (2)
        elif (wc < 1500):
            return (1)
    elif size == 500:
        if (wc < 5500):
            return (5)
        elif (wc < 7000):
            return (4)
        elif (wc < 8500):
            return (3)
        elif (wc <10000):
            return (2)
        elif (wc < 11500):
            return (1)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = "PUSH_SWAP TEST")
    parser.add_argument("--PUSH_SWAP_PATH", type=str, default="./", help="PUSH_SWAP 경로")
    parser.add_argument("--CHECKER_LINUX_PATH", type=str, default="./", help="CHECKER 경로")
    
    args = parser.parse_args()

    warpping_print("PUSH_SWAP TESTER!!!")

    ###############TEST1##################
    warpping_print("TEST 1. ERROR CASE ")

    not_number = ["-a", "b", "c"]
    print(f"\n매개변수가 숫자가 아니라면? - inputs : {not_number}")
    run_push_swap(not_number, args)

    dup_number = [-943, 5, 44, 32, -943]
    print(f"\n매개변수에 숫자가 중복된다면? - inputs : {dup_number}")
    run_push_swap(dup_number, args)

    max_int_number = [3, 2, 1, MAX_INT+5]
    min_int_number = [-1, -5, -4, MIN_INT-3]
    print(f"\n매개변수에 숫자가 int max를 넘어간다면 : {max_int_number}")
    run_push_swap(max_int_number, args)
    print(f"\n매개변수에 숫자가 int min을 넘어간다면 : {min_int_number}")
    run_push_swap(min_int_number, args)

    print(f"\n매개변수에 아무것도 없다면\n")
    run_push_swap([], args)

    ###############TEST2##################
    warpping_print("TEST 2. 이미 정렬된")
    print(f"\npush_swap 42")
    run_push_swap([42], args)

    print(f"\npush_swap 0 1 2 3")
    run_push_swap([0, 1, 2, 3,], args)

    print(f"\npush_swap 0 1 2 3 4 5 6 7 8 9")
    run_push_swap([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], args)

    ###############TEST3##################
    warpping_print("TEST 3. SIMPIE CASE")
    print("\n[2 1 0] case")
    wc, solutions = run_push_swap([2, 1, 0], args, True)
    print(solutions)
    print(f"check command num : {wc}")

    ###############TEST4##################
    warpping_print("TEST 4. Another version")
    print("\n[1 5 2 4 3] case")
    wc, solutions = run_push_swap([1, 5, 2, 4, 3], args, True)
    print(solutions)
    print(f"check command num : {wc}")

    random_lst = make_random_lst(5)
    print(f"\nrandom 5 case - inputs : {random_lst}")
    wc, solutions = run_push_swap(random_lst, args, True)
    print(solutions)
    print(f"check command num : {wc}")

    ###############TEST5##################
    warpping_print("TEST 5. MIDDLE VERSION")
    random_lst = make_random_lst(100)
    print(f"\n[random 100 case] - inputs : {random_lst}")
    print(f"[len] : {len(random_lst)}")
    wc, solutions = run_push_swap(random_lst, args, True)
    print(solutions)
    print(f"check command num : {wc}")
    score_1 = check_score(100, wc)
    print(f"Score : {score_1}")

    random_lst = make_random_lst(500)
    print(f"\n[random 500 case] - inputs : {random_lst}")
    print(f"[len] : {len(random_lst)}")
    wc, solutions = run_push_swap(random_lst, args, True)
    print(solutions)
    print(f"check command num : {wc}")
    score_2 = check_score(500, wc)
    print(f"Score : {score_2}")

    print(f"\nTOTAL SCORE : {score_1 + score_2}")
    print("="*100)