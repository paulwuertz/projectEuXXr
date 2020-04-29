use std::{
    fs::File,
    io::prelude::*,
    env
};

#[derive(Debug, Clone)]
struct Vertice {
    weight:     u32,
    entered :   bool,
    visited :   bool,
    best_value: u32,
    x_prev: usize,
    y_prev: usize,
}

#[derive(Debug)]
struct Lattice {
    x_size : usize,
    y_size : usize,
    vertices: Vec<Vec<Vertice>>,
}

impl Lattice {
    fn init(x : usize, y : usize) -> Lattice {
        Lattice { 
            x_size : x,
            y_size : y,
            vertices: vec![vec![Vertice {
                weight:     0,
                entered:    false,
                visited:    false,
                best_value: 0,
                x_prev: 0,
                y_prev: 0,
            };y]; x],            
        }
    }
    fn set_prev(&mut self, x : usize, y : usize, x_prev : usize, y_prev : usize){
        self.vertices[x][y].x_prev = x_prev;
        self.vertices[x][y].y_prev = y_prev;
    }
    fn set_weight(&mut self, x : usize, y : usize, value : u32){
        self.vertices[x][y].weight = value;
    }
    fn get_weight(&mut self, x : usize, y : usize) -> u32 {
        self.vertices[x][y].weight
    }
    fn set_value(&mut self, x : usize, y : usize, value : u32){
        self.vertices[x][y].best_value = value;
    }
    fn get_value(&mut self, x : usize, y : usize) -> u32{
        self.vertices[x][y].best_value
    }
    fn set_visited(&mut self, x : usize, y : usize){
        self.vertices[x][y].visited = true;
    }
    fn get_visited(&mut self, x : usize, y : usize) -> bool{
        self.vertices[x][y].visited
    }
    fn set_entered(&mut self, x : usize, y : usize){
        self.vertices[x][y].entered = true;
    }
    fn get_entered(&mut self, x : usize, y : usize) -> bool{
        self.vertices[x][y].entered
    }
    fn init_weights_from_file(x : usize, y : usize, f : String) -> Lattice {
        let mut file = File::open(f).unwrap();
        let mut weights = String::new();
        file.read_to_string(&mut weights).unwrap();
        let rows : Vec<&str> = weights.split("\n").collect();
        let mut n_lattice : Lattice = Lattice::init(x, y);
        for (y, row) in rows.iter().enumerate() {
            if row.len() < y { continue; }
            let elements : Vec<&str> = row.split(",").collect();
            for (x, e) in elements.iter().enumerate() {
                //println!("{}", e);
                n_lattice.set_weight(x, y, e.parse().unwrap());
            }
        }
        return n_lattice;
    }

    //takes a weight initalized lattice and finds
    //the shortest path from top_l to bottom_r corner
    fn shortest_binary_walk(&mut self){ 
        let mut ref_val = self.get_weight(0, 0);
        self.set_value(0, 0, ref_val);
        //init border row and colomn
        for i in 1..self.x_size {
            ref_val = self.get_weight(i, 0) + self.get_value(i-1, 0);
            self.set_value(i, 0, ref_val);
        }
        for i in 1..self.y_size {
            ref_val = self.get_weight(0, i) + self.get_value(0, i-1);
            self.set_value(0, i, ref_val);
        }
        //fill in the rest
        for x in 1..self.x_size {
            for y in 1..self.y_size {
                let best_pred = if self.get_value(x, y-1) < self.get_value(x-1, y) {
                    self.get_value(x, y-1)
                } else {
                    self.get_value(x-1, y)
                };
                let self_val = self.get_weight(x, y);
                self.set_value(x, y, best_pred+self_val);
            }
        }
    }

    //takes a weight initalized lattice and finds
    //the shortest path from top_l to bottom_r corner
    fn shortest_trinary_walk(&mut self){ 
        let mut ref_val;
        for i in 0..self.y_size {
            ref_val = self.get_weight(i, 0);
            self.set_value(0, i, ref_val);
            self.set_entered(0, i);
        }
        let mut min_val;
        let mut min_col;
        let mut min_row;
        let mut col : usize = 1;
        while col < 80 {
            min_val = 0x7FFF_FFFF;
            min_col = 0x7FFF_FFFF;
            min_row = 0x7FFF_FFFF;
            //get lowest not checked in the 2 advancing columns
            for y in 1..self.y_size {
                if self.get_value(col-1, y) < min_val && !self.get_visited(col-1, y) && self.get_entered(col-1, y) {
                    min_val = self.get_value(col-1, y);
                    min_col = col-1;
                    min_row = y;
                }
                if self.get_value(col, y) < min_val && !self.get_visited(col, y) && self.get_entered(col, y) {
                    min_val = self.get_value(col, y);
                    min_col = col;
                    min_row = y;
                }
            }
            self.set_visited(min_col, min_row);
            println!("visited {} {}", min_col, min_row);
            if min_col+1 < self.x_size && !self.get_entered(min_col+1, min_row) {
                let v = self.get_weight(min_col+1, min_row);
                self.set_value(min_col+1, min_row, v+min_val);
                self.set_entered(min_col+1, min_row);
                self.set_prev(min_col+1, min_row, min_col, min_row);
            }
            if min_row+1 < self.y_size && !self.get_entered(min_col, min_row+1) {
                let v = self.get_weight(min_col, min_row+1);
                self.set_value(min_col, min_row+1, v+min_val);
                self.set_entered(min_col, min_row+1);
                self.set_prev(min_col, min_row+1, min_col, min_row);
            }
            if min_row-1 >= 0 && !self.get_entered(min_col, min_row-1) {
                let v = self.get_weight(min_col, min_row-1);
                self.set_value(min_col, min_row-1, v+min_val);
                self.set_entered(min_col, min_row-1);
                self.set_prev(min_col, min_row-1, min_col, min_row);
            }
            if self.col_trinary_fully_visited(col) {
                col += 1;
            }
        }
    }

    fn col_trinary_fully_visited(&mut self, col: usize) -> bool {
        for y in 0..self.y_size {
            if !self.get_entered(col, y) {
                return false; 
            }
        } 
        return true;
    }
    //fn shortest_quaternal_walk(&self){}
}

fn main(){
    let args: Vec<String> = env::args().collect();
    if args.len() > 1 {
        let problem = &args[1];
        if problem == "81" {
            let mut l2: Lattice = Lattice::init_weights_from_file(
                                80, 80, String::from("../resources/p081_matrix.txt")
                            );
            l2.shortest_binary_walk();
            println!("l2 {:?} l2", l2);
        } else if problem == "82" {
            let mut l3: Lattice = Lattice::init_weights_from_file(
                80, 80, String::from("../resources/p082_matrix.txt")
            );
            l3.shortest_trinary_walk();
            let mut min_val = 0x7FFF_FFFF;
            let mut min_row = 0x7FFF_FFFF;
            for i in 0..l3.y_size {
                if l3.get_value(l3.x_size-1, i) < min_val {
                    min_row = i;
                    min_val = l3.get_value(l3.x_size-1, i);
                    println!("l3 {} {}", i, l3.get_value(l3.x_size-1, i));
                }
            }
            let mut col = 79;
            let mut row = min_row;
            while col != 0 && row != 0 {
                print!("({}, {}) -> ", col, row);
                let col_temp = col;
                col = l3.vertices[col_temp][row].x_prev;
                row = l3.vertices[col_temp][row].y_prev;
            }
            println!("({}, {})!!!", col, row);
        } /*else {
            let mut l4: Lattice = Lattice::init_weights_from_file(
                80, 80, String::from("../resources/p083_matrix.txt")
            );
            l4.shortest_quaternal_walk();
            println!("l4 {:?}", l4);
        }*/
    }
}