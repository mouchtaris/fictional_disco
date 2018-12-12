# vim: et ts=2 sw=2

struct ConfDirStorage
  def initialize(
    @root : String,
    @path = [] of String,
  )
  end

  def root
    @root
  end

  def path
    case @path.size
    when 0
      ""
    else
      @path.reduce { |a, b| File.join a, b }
    end
  end

  def value_key(name)
    "#{name}.txt"
  end

  def subconf_key(name)
    name
  end

  def absolute_key(key)
    File.join @root, path, key
  end

  def lines(name)
    File.read_lines absolute_key(value_key(name))
  end

  def value(name)
    lines(name).first
  end

  def list
    lines("list")
  end

  def subconf(name)
    self.class.new(@root, @path.dup << subconf_key(name).to_s)
  end
end
