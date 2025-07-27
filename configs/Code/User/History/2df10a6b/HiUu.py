import random
import time
from mochi import addo

def play_addo_game(rounds=5):
    print("Welcome to the Addo Addition Game!")
    print(f"You will be given {rounds} addition problems. Try to answer as quickly as possible!\n")
    correct = 0
    total_time = 0.0

    for i in range(1, rounds + 1):
        a = random.randint(1, 100)
        b = random.randint(1, 100)
        print(f"Round {i}: What is {a} + {b}?")
        start = time.time()
        try:
            user_answer = int(input("Your answer: "))
        except ValueError:
            print("Invalid input! Skipping this round.")
            continue
        end = time.time()
        elapsed = end - start
        total_time += elapsed

        correct_answer = addo(a, b)
        if user_answer == correct_answer:
            print(f"Correct! (Answered in {elapsed:.2f} seconds)\n")
            correct += 1
        else:
            print(f"Wrong! The correct answer was {correct_answer}. (Answered in {elapsed:.2f} seconds)\n")

    print(f"Game Over! You got {correct} out of {rounds} correct.")
    print(f"Average response time: {total_time/rounds:.2f} seconds per question.")

if __name__ == "__main__":
    play_addo_game()