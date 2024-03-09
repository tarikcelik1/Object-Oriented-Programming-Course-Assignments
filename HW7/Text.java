public class Text extends DatasetObject implements NonVisual, NonPlayable { // to define Text class.
    public Text(String name, String otherInfo) { // to define constructor.
        super(name, otherInfo);
    }

    public void info() { // to define infor function.
        System.out.println("Text object: " + getName() + ", " + getOtherInfo());
    }
}