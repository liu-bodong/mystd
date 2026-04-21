import argparse
import random
import os
from pathlib import Path
import sys
import threading

# TODO: Add multithreading in future, or numpy to speed up

BILLION = 1000000000
MILLION = 1000000
KILO = 1000


def generate_rand_ints_uniform(seed: int, size: int, min: int, max: int):
    min_max = "-".join([str(min), str(max)])
    ls = generate_filename(["uniform", seed, size, min, max])
    min_max = "-".join([ls[-2], ls[-1]])

    filepath = Path(".") / "data" / ("_".join(ls[:-2] + [min_max]) + ".txt")
    random.seed(seed)
    with open(filepath, "w") as f:
        for _ in range(size):
            num = random.randint(min, max)
            f.write(str(num) + "\n")

    return True


def generate_filename(ls):
    # dc = {BILLION: "B", MILLION: "M", KILO: "K"}

    ret: list[str] = []
    for e in ls:
        res = {"B": 0, "M": 0, "K": 0}
        if type(e) is int:
            while e:
                if e >= BILLION:
                    e = e // BILLION
                    res["B"] += 1
                elif e >= MILLION:
                    e = e // MILLION
                    res["M"] += 1
                elif e >= KILO:
                    e = e // KILO
                    res["K"] += 1
                else:
                    break
            # e = str(e) + str(res["K"]) + str(res["M"]) + str(res["B"])\
            e = str(e)
            for k in ["K", "M", "B"]:
                e += "".join([k for _ in range(res[k])])
        ret.append(e)

    return ret


if __name__ == "__main__":
    seed = 42
    args = sys.argv[1:]

    parser = argparse.ArgumentParser()
    parser.add_argument("--seed", type=int, default=42)
    parser.add_argument("--size", type=int)
    parser.add_argument("--range", type=int, nargs=2)
    # TODO: add parser flags for other way of generation

    args = parser.parse_args()

    # generate_rand_ints_uniform(seed, 10000, 0, 1000000)
    min, max = min(args.range), max(args.range)
    generate_rand_ints_uniform(args.seed, args.size, min, max)
