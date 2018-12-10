class Logger
  def initialize(
    @loggert_out : IO::FileDescriptor,
    @logger_name : Symbol | String,
  )
  end

  def log(level, msg)
    STDERR.puts("#{@logger_name} | [#{level}] #{msg}")
  end

  def info(msg)
    log(:INFO, msg)
  end
end
