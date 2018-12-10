# vim: et ts=2 sw=2
require "./logging"
require "./logger"
require "./sms"

class Cli
  include Sms
  include Logging

  @project_root : String

  def initialize(argv)
    @project_root = argv.first
    @logger = Logger.new(STDERR, :Cli)
  end

  def main
    log.info "Hello. This is Source Management System."
  end
end

Cli.new(ARGV).main
