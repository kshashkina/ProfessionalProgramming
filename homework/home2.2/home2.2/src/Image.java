import java.io.*;
import java.util.*;

class Image {
    private List<List<Color>> pixels = new ArrayList<>();

    public void load(String inputFileName) throws IOException {
        BufferedReader inputFile = new BufferedReader(new FileReader(inputFileName));
        String line;
        int row = 0;
        while ((line = inputFile.readLine()) != null) {
            if (row >= 16) {
                inputFile.close();
                throw new IllegalArgumentException("Too many lines in input file");
            }
            List<Color> parsedLine = parseLine(line);
            if (parsedLine.size() != 16) {
                inputFile.close();
                throw new IllegalArgumentException("Invalid number of pixels in a line");
            }
            pixels.add(parsedLine);
            row++;
        }
        inputFile.close();
        if (row != 16) {
            throw new IllegalArgumentException("Not enough lines in input file");
        }
    }

    private List<Color> parseLine(String line) {
        List<Color> row = new ArrayList<>();
        String[] parts = line.split(" ");
        for (String part : parts) {
            String[] colorValues = part.split(",");
            if (colorValues.length != 3) {
                throw new IllegalArgumentException("Invalid pixel format");
            }
            row.add(new Color(
                    Integer.parseInt(colorValues[0]),
                    Integer.parseInt(colorValues[1]),
                    Integer.parseInt(colorValues[2])
            ));
        }
        return row;
    }

    public void transform(Color favoriteColor, Color unfavoriteColor) {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                Color pixel = pixels.get(i).get(j);
                if (pixel.equals(favoriteColor)) {
                    if (i > 0 && j > 0) {
                        pixels.get(i - 1).set(j - 1, favoriteColor);
                    }
                }
                if (pixel.equals(unfavoriteColor)) {
                    pixels.get(i).set(j, favoriteColor);
                }
            }
        }
    }

    public void save(String outputFileName) throws IOException {
        BufferedWriter outputFile = new BufferedWriter(new FileWriter(outputFileName));
        for (List<Color> row : pixels) {
            for (int j = 0; j < row.size(); j++) {
                outputFile.write(row.get(j).toString());
                if (j < row.size() - 1) {
                    outputFile.write(" ");
                }
            }
            outputFile.write("\n");
        }
        outputFile.close();
    }
}
