# vim: et ts=2 sw=2

struct LineAdder
  def initialize(@get_val : Proc(String))
  end

  def call(io : IO)
    io.puts @get_val.call
  end
end
