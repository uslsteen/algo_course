use std::io;

fn input_i32() ->i32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    return input.trim().parse().unwrap();
}

fn main() {
    let num_of_coins: i32 = input_i32();
    let mut vec : Vec<i32> = Vec::new();

    for i in 0..num_of_coins {
        let coin : i32 = input_i32();
        vec.push(coin);
    }

    let mut sum : i32 = 0;

    for vec_it in vec.iter() {
        if vec_it > &(sum + 1) {
            break;
        }
        sum = sum + vec_it;
    }
    sum +=1;

    println!("{}", sum);
}
