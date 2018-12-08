fn min<T: PartialOrd>(a: T, b: T) -> T {
    if a < b { a } else { b }
}

#[derive(Debug)]
struct Coord {
    from: usize,
    to: usize,
    first: usize,
    last: usize,
}

impl Coord {
    fn new_in(from: usize, to: usize) -> Coord {
        Coord { from, to, first: 0, last: 0 }
    }

    fn new() -> Coord { Self::new_in(0, 0) }

    fn for_data<T>(data: &[T]) -> Coord { Self::new_in(0, data.len()) }
}

#[derive(Debug)]
struct MutBufferView<'data, T> {
    data: &'data mut[T],
    coord: Coord,
}

impl <'data, T> MutBufferView<'data, T> {
    fn remaining(&self) -> usize {
        self.coord.last - self.coord.first
    }

    fn reset(self) -> Self {
        let coord = Coord {
            first: self.coord.from,
            last: self.coord.to,
            ..self.coord
        };
        MutBufferView { coord, ..self }
    }

    fn put_other<'data2: 'data>(self, other: &'data2 mut MutBufferView<'data2, T>) -> Self
        where
            T: Copy
    {
        let limit = min(self.remaining(), other.remaining());
        let self2 = MutBufferView {
            coord: Coord { first: self.coord.first + limit, ..self.coord },
            ..self
        };
        for i in 0..limit {
            self2.data[self.coord.first + i] = other.data[other.coord.first + i]
        }
        other.coord = Coord { first: other.coord.first + limit, ..other.coord };
        self2
    }
}

struct Builder;

impl Builder {
  fn new_in<T>(data: &mut [T], from: usize, to: usize) -> MutBufferView<T> {
      let coord = Coord::new_in(from, to);
      MutBufferView { data, coord }.reset()
  }
}

fn main() {
    let mut data1 = [1, 2, 3, 4, 5, 6, ];
    let mut data2 = [7, 8, 9, 10];
    {
        let buf1 = Builder::new_in(&mut data1, 2, 5);
        let mut buf2 = Builder::new_in(&mut data2, 1, 3);
        println!("{} {:?}", buf1.remaining(), buf1);
        println!("{} {:?}", buf2.remaining(), buf2);
        println!("{:?}", data2);
        let buf3 = buf1.put_other(&mut buf2);
        println!("{} {:?}", buf3.remaining(), buf3);
        //    println!("{} {:?}", buf2.remaining(), buf2);
        println!("{:?}", &mut data2);
    }
}
