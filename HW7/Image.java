public class Image extends DatasetObject implements Visual, NonPlayable { // to define image class.
    private String dimensions;

    public Image(String name, String dimensions, String otherInfo) { // to define constructor.
        super(name, otherInfo); // to assign parameters to members with using constructor of abstract class.
        this.dimensions = dimensions;
    }

    public String getDimensions() { // to define getter function for dimensions.
        return dimensions;
    }

    public void info() { // to define info function for get info of audio object.
        System.out.println("Image object: " + getName() + ", " + getDimensions() + ", " + getOtherInfo());
    }
}