import java.util.EnumMap;
import java.util.Map;
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

        Map<Song, Map<Command, Song>> transitions = createTransitions();

        while (currentSong != Song.End) {
            System.out.println("Currently playing: " + currentSong);
            System.out.print("Enter command (sad, fun, silly, dangerous): ");
            String userInput = scanner.nextLine().trim().toLowerCase();

            Command command = getCommand(userInput);
            currentSong = getNextSong(currentSong, command, transitions);
        }

        System.out.println("Terminating program. Playing: " + currentSong);
        scanner.close();
    }

    private static Map<Song, Map<Command, Song>> createTransitions() {
        Map<Song, Map<Command, Song>> transitions = new EnumMap<>(Song.class);

        transitions.put(Song.Intro, Map.of(
                Command.Sad, Song.End,
                Command.Fun, Song.Starman,
                Command.Dangerous, Song.LetItBe
        ));
        transitions.put(Song.Starman, Map.of(
                Command.Silly, Song.Intro,
                Command.Dangerous, Song.ShowMustGoOn,
                Command.Fun, Song.End
        ));
        transitions.put(Song.ShowMustGoOn, Map.of(
                Command.Sad, Song.LetItBe,
                Command.Fun, Song.Starman
        ));
        transitions.put(Song.LetItBe, Map.of(
                Command.Dangerous, Song.Intro,
                Command.Silly, Song.ShowMustGoOn
        ));

        return transitions;
    }

    private static Song getNextSong(Song currentSong, Command command, Map<Song, Map<Command, Song>> transitions) {
        return transitions.getOrDefault(currentSong, Map.of()).getOrDefault(command, currentSong);
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
