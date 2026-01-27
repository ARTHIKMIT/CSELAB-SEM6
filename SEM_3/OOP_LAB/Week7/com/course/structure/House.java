package com.course.structure;

public class House extends Building {
    public int numberOfBedrooms;
    public int numberOfBaths;

    public House(){
    }
    public House(int sq, int st, int beds, int baths){
        super(sq, st);
        numberOfBedrooms = beds;
        numberOfBaths = baths;
    }
}
