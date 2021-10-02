
use std::io;

fn input_array(size : usize) -> Vec<i32> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut vec = Vec::new();

    while vec.len() != size {
        vec = input.split_whitespace().map(|s| s.parse().unwrap()).collect();
    }

    vec
}

fn input_usize() -> usize {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    return input.trim().parse().unwrap();
}

fn get_intersetct(vec1: &Vec<i32>, vec2 : &Vec<i32>, size1 : usize, size2: usize) {

    let mut i1 : usize = 0; 
    let mut i2 : usize = 0;

    while i1 < size1 && i2 < size2 {
        if vec1[i1] == vec2[i2] {
            print!("{} ", vec1[i1]);
            i1 += 1; i2 +=1;
        }
        else if vec1[i1] > vec2[i2] {
            i2 += 1;
        }
        else {
            i1 += 1;
        }
    }
}


fn main() {

    let size1 : usize = input_usize();
    let size2 : usize = input_usize();

    let data1 : Vec<i32> = input_array(size1);
    let data2 : Vec<i32> = input_array(size2);

    get_intersetct(&data1, &data2, size1, size2);
}
