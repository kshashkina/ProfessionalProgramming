import java.util.Scanner;

public class SongPlayerFSM {
    enum Song {
        Intro,
        Starman,
        ShowMustGoOn,
        LetItBe,
        End
    }
    enum Command {
        Sad,
        Fun,
        Silly,
        Dangerous
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Song currentSong = Song.Intro;

        while (currentSong != Song.End) {
            System.out.println("Currently playing: " + currentSong);
            System.out.print("Enter command (sad, fun, silly, dangerous): ");
            String userInput = scanner.nextLine().trim().toLowerCase();

            Command command = getCommand(userInput);

            switch (currentSong) {
                case Intro:
                    switch (command) {
                        case Sad:
                            currentSong = Song.End;
                            break;
                        case Fun:
                            currentSong = Song.Starman;
                            break;
                        case Dangerous:
                            currentSong = Song.LetItBe;
                            break;
                        default:
                            break; // Replay Intro for other commands
                    }
                    break;
                case Starman:
                    switch (command) {
                        case Silly:
                            currentSong = Song.Intro;
                            break;
                        case Dangerous:
                            currentSong = Song.ShowMustGoOn;
                            break;
                        case Fun:
                            currentSong = Song.End;
                            break;
                        default:
                            break;
                    }
                    break;
                case ShowMustGoOn:
                    switch (command) {
                        case Sad:
                            currentSong = Song.LetItBe;
                            break;
                        case Fun:
                            currentSong = Song.Starman;
                            break;
                        default:
                            break;
                    }
                    break;
                case LetItBe:
                    switch (command) {
                        case Dangerous:
                            currentSong = Song.Intro;
                            break;
                        case Silly:
                            currentSong = Song.ShowMustGoOn;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        System.out.println("Terminating program. Playing: " + currentSong);
        scanner.close();
    }

    // Helper method to convert user input string to Command enum
    private static Command getCommand(String commandStr) {
        switch (commandStr) {
            case "sad":
                return Command.Sad;
            case "fun":
                return Command.Fun;
            case "silly":
                return Command.Silly;
            case "dangerous":
                return Command.Dangerous;
            default:
                return Command.Sad;
        }
    }
}
