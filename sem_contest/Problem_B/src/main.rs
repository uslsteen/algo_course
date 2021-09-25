use std::io;

fn input_data() -> Vec<&str> {

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let vec : Vec<&str> = input.split(' ').collect();

    return vec;
}

fn get_substr(ind_n : i32, ind_k : i32, ind_l : i32) -> {

}

fn main() {
    let user_input : Vec<&str> = input_data();

    let mut string = String::new();

    get_substr(); 
}
