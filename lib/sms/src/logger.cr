# vim: et ts=2 sw=2

class Logger
  def initialize(
    @logger_out : IO::FileDescriptor,
    @logger_name : String,
  )
  end

  Levels = {
    debug: 0,
    trace: 100,
    info: 200,
    warn: 300,
    critical: 400,
    disaster: 500,
  }

  def format(level, msg)
    sprintf("[ %5s:%03d ] || %-10s || %s", level, Levels[level], @logger_name, msg)
  end

  def log(level, msg)
    @logger_out.puts format(level, msg)
  end

  def debug(msg)
    log(:debug, msg)
  end

  def trace(msg)
    log(:trace, msg)
  end

  def info(msg)
    log(:info, msg)
  end

  def warn(msg)
    log(:warn, msg)
  end

  def critical(msg)
    log(:critical, msg)
  end

  def disaster(msg)
    log(:disaster, msg)
  end
end
