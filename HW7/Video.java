public class Video extends DatasetObject implements Playable, Visual { // to define Video class.
    private String duration;

    public Video(String name, String duration, String otherInfo) { // to define constructor.
        super(name, otherInfo); // to use the consturctor of abstract class.
        this.duration = duration;
    }

    public String getDuration() { // to define a getter function for duration.
        return duration;
    }

    public void info() { // to define info function.
        System.out.println("Video object: " + getName() + ", " + getDuration() + ", " + getOtherInfo());
    }

}