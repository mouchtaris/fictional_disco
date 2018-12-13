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

  def mkdir_p
    Dir.mkdir_p(File.join(@root, path))
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
    path = absolute_key(value_key(name))
    if File.exists?(path)
      File.read_lines path
    else
      [] of String
    end
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

  def add(name, val)
    prev = lines(name)
    next_ = (prev.dup << val).sort.uniq

    if prev != next_
      path = absolute_key(value_key(name))

      mkdir_p

      File.open(path, "w") do |fout|
        next_.each { |line| fout.puts line }
      end
    end
  end
end
