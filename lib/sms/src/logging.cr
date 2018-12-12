# vim: et ts=2 sw=2

module Logging
  @logger : Logger

  def self.logger_for(name)
    Logger.new(STDERR, name)
  end

  def log
    @logger
  end
end
