
use std::io;
use std::ops::BitXor;
use std::ops::BitXorAssign;

static CHUNK_SIZE : i32= 32;
static MAX_SET_ELEM : i32 = 20000;


fn input_i32() ->i32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    return input.trim().parse().unwrap();
}

pub struct Set {
    m_data : Vec<i32>,
    m_max_elem : i32,
}

impl Set {
    pub fn new(max_elem : i32) -> Option<Set> {
        if max_elem == MAX_SET_ELEM {
            let mut data = Vec::with_capacity(max_elem as usize);
            data.resize(max_elem as usize, 0);

            Some(Set{m_data : data, m_max_elem : max_elem })
        }
        else {
            None
        }
    }

    pub fn insert(&mut self, elem : i32) -> bool {
        if elem > self.m_max_elem {
            return false;
        }
        self.m_data[(elem / CHUNK_SIZE) as usize] |= (1 << (elem % CHUNK_SIZE));
        return true;
    }

    pub fn erase(&mut self, elem : i32) -> bool {
        if elem > self.m_max_elem {
            return false;
        }

        self.m_data[(elem / CHUNK_SIZE) as usize] &= (1 << (elem % CHUNK_SIZE));
        return true;
    }

    pub fn contains(&mut self, elem : i32) -> i32 {
        return (self.m_data[(elem / CHUNK_SIZE) as usize] >> (elem % CHUNK_SIZE)) & 1;
    }

    pub fn dump(&mut self) {
        for elem in 0..self.m_max_elem {
            if self.contains(elem) == 1 {
                println!("{}", elem);
            }
        }
        println!();
    }
}

impl BitXorAssign for Set {

    fn bitxor_assign(&mut self, other: Self) {

        self.m_max_elem = other.m_max_elem;

        for i in 0..self.m_max_elem {
            self.m_data[i as usize] ^= other.m_data[i as usize];
        }
    }
}

impl BitXor for Set {

    type Output = Self;

    fn bitxor(self, rhs: Self) -> Self::Output {
        let mut self_cp : Set = self;
        self_cp ^= rhs;
        Self{m_data : self_cp.m_data, m_max_elem : self_cp.m_max_elem}
    }
}


pub fn construct_n_init(max_elem : i32) -> Option<Set> {
    let mut set  : Set = Set::new(max_elem).unwrap();
    /*
    match set {
        Some(set) => {
            println!("Set was constructed successful")
        },
        None => println!("Set wasn't constructed successful")
    }*/

    let mut elem : i32 = input_i32();

    while elem != 0 {
        set.insert(elem);
        elem = input_i32();
    }

    return Some(set);
}


fn main() {
    let max_elem: i32 = 20000;

    let set1 : Set = construct_n_init(max_elem).unwrap();
    let set2 : Set = construct_n_init(max_elem).unwrap();

    let mut set_res : Set = set1^set2; 
    set_res.dump();
}
