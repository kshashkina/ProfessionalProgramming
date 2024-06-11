import java.io.*;
import java.util.*;

public class ImageProcessor {

    public static List<String> split(String str, char delimiter) {
        List<String> tokens = new ArrayList<>();
        String[] parts = str.split(String.valueOf(delimiter));
        Collections.addAll(tokens, parts);
        return tokens;
    }

    public static boolean isValidColorValue(String str) {
        try {
            int value = Integer.parseInt(str);
            return (value >= 0 && value <= 255);
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static boolean isValidColorValue(int value) {
        return (value >= 0 && value <= 255);
    }

    public static List<int[]> parseLine(String line) {
        List<int[]> pixels = new ArrayList<>();
        List<String> parts = split(line, ' ');
        for (String part : parts) {
            List<String> colorValues = split(part, ',');
            if (colorValues.size() != 3 ||
                    !isValidColorValue(colorValues.get(0)) ||
                    !isValidColorValue(colorValues.get(1)) ||
                    !isValidColorValue(colorValues.get(2))) {
                throw new IllegalArgumentException("Invalid pixel format");
            }
            int[] pixel = {
                    Integer.parseInt(colorValues.get(0)),
                    Integer.parseInt(colorValues.get(1)),
                    Integer.parseInt(colorValues.get(2))
            };
            pixels.add(pixel);
        }
        return pixels;
    }

    public static void processImage(String inputFileName, int[] favoriteColor, String outputFileName, int[] unfavoriteColor) throws IOException {
        BufferedReader inputFile = new BufferedReader(new FileReader(inputFileName));
        List<List<int[]>> image = new ArrayList<>(16);

        String line;
        int row = 0;
        while ((line = inputFile.readLine()) != null) {
            if (row >= 16) {
                inputFile.close();
                throw new IllegalArgumentException("Too many lines in input file");
            }
            List<int[]> parsedLine = parseLine(line);
            if (parsedLine.size() != 16) {
                inputFile.close();
                throw new IllegalArgumentException("Invalid number of pixels in a line");
            }
            image.add(parsedLine);
            row++;
        }
        inputFile.close();

        if (row != 16) {
            throw new IllegalArgumentException("Not enough lines in input file");
        }

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                int[] pixel = image.get(i).get(j);

                if (Arrays.equals(pixel, favoriteColor)) {
                    if (i > 0 && j > 0) {
                        image.get(i - 1).set(j - 1, favoriteColor);
                    }
                }

                if (Arrays.equals(pixel, unfavoriteColor)) {
                    image.get(i).set(j, favoriteColor);
                }
            }
        }

        BufferedWriter outputFile = new BufferedWriter(new FileWriter(outputFileName));
        for (List<int[]> rowPixels : image) {
            for (int j = 0; j < rowPixels.size(); j++) {
                int[] pixel = rowPixels.get(j);
                outputFile.write(pixel[0] + "," + pixel[1] + "," + pixel[2]);
                if (j < rowPixels.size() - 1) {
                    outputFile.write(" ");
                }
            }
            outputFile.write("\n");
        }
        outputFile.close();
    }
}
