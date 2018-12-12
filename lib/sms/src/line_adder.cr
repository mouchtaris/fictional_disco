# vim: et ts=2 sw=2

struct LineAdder
  def initialize(
    @get_val : Proc(String),
    @indent = 0
  )
  end

  def indent_incr
    LineAdder.new(@get_val, @indent + 1)
  end

  def indentation
    "    " * @indent
  end

  def call(io : IO)
    io.puts "#{indentation}#{@get_val.call}"
  end
end
