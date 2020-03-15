//YUNPENG_LING   JAVA PROJECT 2  15-MARCH-JUPITER TIME


import java.util.Random;
import java.util.Scanner;
 
public class RockPaperScissors {
    private User user;
    private Computer computer;
    private int userScore;
    private int computerScore;
    private int numberOfGames;
 
    private enum Choice {
        ROCK, PAPER, SCISSORS;
 
        
          //Compares this Choice with another Choice to determining a tie, a win, or
          //a loss.
        public int compareChoices(Choice otherChoice) {
            // Tie
            if (this == otherChoice)
                return 0;
 
            switch (this) {
            case ROCK:
                return (otherChoice == SCISSORS ? 1 : -1);
            case PAPER:
                return (otherChoice == ROCK ? 1 : -1);
            case SCISSORS:
                return (otherChoice == PAPER ? 1 : -1);
            }
 
            // Should never reach here
            return 0;
        }
    }
 
    private class User {
        private Scanner inputScanner;
 
        public User() {
            inputScanner = new Scanner(System.in);
        }
 
        public Choice getChoice() {
            // Prompt the user
            System.out.println("Let's Play Rock Paper Scissors!!!");
            System.out.println("Rock, paper, or scissors? Please enter your choice ");
            // Get the user input
            String userInput = inputScanner.nextLine();
            userInput = userInput.toUpperCase();
            char firstLetter = userInput.charAt(0);
            if (firstLetter == 'R' || firstLetter == 'P' || firstLetter == 'S') {
                // User has entered a valid input
                switch (firstLetter) {
                case 'R':
                    return Choice.ROCK;
                case 'P':
                    return Choice.PAPER;
                case 'S':
                    return Choice.SCISSORS;
                }
            }
 
            // If user has not entered a valid input. ask for input again.
            return getChoice();
        }
 
        public boolean playAgain() {
            System.out.print("Would you like to play again? ");
            String userInput = inputScanner.nextLine();
            userInput = userInput.toUpperCase();
            return userInput.charAt(0) == 'Y';
        }
    }
 
    private class Computer {
        public Choice getChoice() {
            Choice[] Choices = Choice.values();
            Random random = new Random();
            int index = random.nextInt(Choices.length);
            return Choices[index];
        }
    }
 
    public RockPaperScissors() {
        user = new User();
        computer = new Computer();
        userScore = 0;
        computerScore = 0;
        numberOfGames = 0;
    }
 
    public void startGame() {
        System.out.println("ROCK, PAPER, SCISSORS!");
 
        // Get Choices
        Choice userChoice = user.getChoice();
        Choice computerChoice = computer.getChoice();
        System.out.println("\nYou chose " + userChoice + ".");
        System.out.println("Computer chose " + computerChoice + ".\n");
 
        // Compare Choices and determine winner
        int compareChoices = userChoice.compareChoices(computerChoice);
        switch (compareChoices) {
        case 0: // Tie
            System.out.println("Tie!");
            break;
        case 1: // User wins
            System.out.println(userChoice + " beats " + computerChoice + ". You won!");
            userScore++;
            break;
        case -1: // Computer wins
            System.out.println(computerChoice + " beats " + userChoice + ". Computer AI WINS.");
            computerScore++;
            break;
        }
        numberOfGames++;
 
        // Ask the user to play again
        if (user.playAgain()) {
            System.out.println();
            startGame();
        } else {
            printGameStats();
        }
    }
 
    
     // Prints out the statistics of the game. Calculates ties as 1/2 a win in
      //percentage won.
    
    private void printGameStats() {
        int wins = userScore;
        int losses = computerScore;
        int ties = numberOfGames - userScore - computerScore;
        double percentageWon = (wins + ((double) ties) / 2) / numberOfGames;
 
        // Line
        System.out.print("+");
        printDashes(68);
        System.out.println("+");
 
        // Print titles
        System.out.printf("|  %6s  |  %6s  |  %6s  |  %12s  |  %14s  |\n",
                "WINS", "LOSSES", "TIES", "GAMES PLAYED", "PERCENTAGE WON");
 
        // Line
        System.out.print("|");
        printDashes(10);
        System.out.print("+");
        printDashes(10);
        System.out.print("+");
        printDashes(10);
        System.out.print("+");
        printDashes(16);
        System.out.print("+");
        printDashes(18);
        System.out.println("|");
 
        // Print values
        System.out.printf("|  %6d  |  %6d  |  %6d  |  %12d  |  %13.2f%%  |\n",
                wins, losses, ties, numberOfGames, percentageWon * 100);
 
        // Line
        System.out.print("+");
        printDashes(68);
        System.out.println("+");
    }
 
    private void printDashes(int numberOfDashes) {
        for (int i = 0; i < numberOfDashes; i++) {
            System.out.print("-");
        }
    }
 
    public static void main(String[] args) {
        RockPaperScissors game = new RockPaperScissors();
        game.startGame();
    }
}