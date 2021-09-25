
mod my_container { 
    use std::io;
    
    static CHUNK_SIZE : i32= 32;

    struct Set {

        m_data : Vec<i32>,
        m_max_elem : i32,
    }

    impl Set {
        pub fn new(max_elem : i32) -> Option<Set> {
            if max_elem == 20000 {
                let data = Vec::with_capacity(max_elem as usize); 
                Some( Set {m_data : data, m_max_elem : max_elem } )
            }
            else {
                None
            }
        }

        pub fn insert(&self, elem : i32) -> bool {
            if elem > self.m_max_elem {
                return false;
            }

            
            self.m_data[(elem / CHUNK_SIZE) as usize] |= 1 << (elem % CHUNK_SIZE);
            return true;
        }

        pub fn erase(&self, elem : i32) -> bool {
            if elem > self.m_max_elem {
                return false;
            }

            self.m_data[(elem / CHUNK_SIZE) as usize] &= (1 << (elem % CHUNK_SIZE));
            return true;
        }

        pub fn contains(&self, elem : i32) -> bool {
            return (self.m_data[(elem / CHUNK_SIZE) as usize] >> (elem % CHUNK_SIZE)) & 1;
        }
    }

    pub fn construct_n_init(max_elem : i32) ->  Option<Set> {
        let mut set = Set::new(max_elem).unwrap();

        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();

        let elem: i32 = input.trim().parse().unwrap();

        while elem != 0 {
            set.insert(elem);
            
            io::stdin().read_line(&mut input).unwrap();
            elem = input.trim().parse().unwrap();
        }

        return Some(set);
    }
}


fn main() {
    let max_elem: i32 = 20000;

    let set1 = my_container::construct_n_init(max_elem).unwrap();
    let set2 = my_container::construct_n_init(max_elem).unwrap();
}
