from mochi import play_addo_game

class TestPlayAddoGame:
    def test_all_answers_correct(self, mocker, capsys):
        rounds = 3
        # Mock random.randint to return predictable pairs
        randint_mock = mocker.patch("random.randint", side_effect=[2, 3, 4, 5, 6, 7])
        # Mock addo to return correct sums
        addo_mock = mocker.patch("mochi.addo", side_effect=[5, 9, 13])
        # Mock input to always return the correct answer
        input_mock = mocker.patch("builtins.input", side_effect=["5", "9", "13"])
        # Mock time.time to simulate 1 second per answer
        time_mock = mocker.patch("time.time", side_effect=[0, 1, 2, 3, 4, 5])

        play_addo_game(rounds=rounds)
        out = capsys.readouterr().out

        assert "You got 3 out of 3 correct." in out
        assert out.count("Correct!") == 3
        assert "Average response time: 1.00 seconds per question." in out

    def test_average_response_time_calculation(self, mocker, capsys):
        rounds = 2
        mocker.patch("random.randint", side_effect=[10, 20, 30, 40])
        mocker.patch("mochi.addo", side_effect=[30, 70])
        mocker.patch("builtins.input", side_effect=["30", "70"])
        # Simulate 2s for first, 4s for second answer
        mocker.patch("time.time", side_effect=[0, 2, 10, 14])

        play_addo_game(rounds=rounds)
        out = capsys.readouterr().out

        assert "Average response time: 3.00 seconds per question." in out

    def test_game_rounds_and_summary(self, mocker, capsys):
        rounds = 4
        mocker.patch("random.randint", side_effect=[1, 2, 3, 4, 5, 6, 7, 8])
        mocker.patch("mochi.addo", side_effect=[3, 7, 11, 15])
        mocker.patch("builtins.input", side_effect=["3", "7", "11", "15"])
        mocker.patch("time.time", side_effect=[0, 1, 2, 3, 4, 5, 6, 7])

        play_addo_game(rounds=rounds)
        out = capsys.readouterr().out

        assert out.count("Round ") == 4
        assert f"You got {rounds} out of {rounds} correct." in out
        assert "Game Over!" in out

    def test_non_integer_input_handling(self, mocker, capsys):
        rounds = 2
        mocker.patch("random.randint", side_effect=[1, 2, 3, 4])
        mocker.patch("mochi.addo", side_effect=[3, 7])
        # First input is invalid, second is valid
        mocker.patch("builtins.input", side_effect=["foo", "7"])
        mocker.patch("time.time", side_effect=[0, 1, 2, 3])

        play_addo_game(rounds=rounds)
        out = capsys.readouterr().out

        assert "Invalid input! Skipping this round." in out
        assert "Correct!" in out or "Wrong!" in out  # Second round proceeds

    def test_all_answers_incorrect(self, mocker, capsys):
        rounds = 2
        mocker.patch("random.randint", side_effect=[1, 2, 3, 4])
        mocker.patch("mochi.addo", side_effect=[3, 7])
        # Provide wrong answers
        mocker.patch("builtins.input", side_effect=["0", "0"])
        mocker.patch("time.time", side_effect=[0, 1, 2, 3])

        play_addo_game(rounds=rounds)
        out = capsys.readouterr().out

        assert "Wrong! The correct answer was" in out
        assert "You got 0 out of 2 correct." in out

    def test_zero_rounds_behavior(self, mocker, capsys):
        rounds = 0
        play_addo_game(rounds=rounds)
        out = capsys.readouterr().out

        assert "You will be given 0 addition problems" in out
        assert "Game Over!" in out
        assert "You got 0 out of 0 correct." in out
        # Avoid division by zero in average response time
        assert "Average response time: N/A (no questions answered)." in out
