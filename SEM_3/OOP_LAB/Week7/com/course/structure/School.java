package com.course.structure;

public class School extends Building {

    public int classrooms;
    public int gradeLevel;
    
    public School(){
    }
    public School(int sq, int st, int c, int g){
        super(sq, st);
        classrooms = c;
        gradeLevel = g;
    }
}